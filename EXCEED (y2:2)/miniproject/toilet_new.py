from re import search
import re
from unittest import result
from pymongo import MongoClient

from fastapi import FastAPI, HTTPException, Query
from pydantic import BaseModel
from fastapi.encoders import jsonable_encoder

from typing import Optional
import datetime

class toilet_c(BaseModel):
    room: int
    time_in: datetime.time
    time_out: datetime.time

class estime(BaseModel):
    name: str
    estime: int
    n: int

client = MongoClient('mongodb://localhost', 27017)
db = client["real_mini"]
collection = db["Toilet"]

app = FastAPI()

@app.get("/toilet/get-info-new")
def get_status():
    room = collection.find({},{"_id": 0})
    estime = collection.find_one({"estimate": "estimate"},{"_id": 0})
    list_room = list(room)
    list_room.pop(3)
    result = list()
    for r in list_room:
        print(r)
        if(r["close"] == 0):
            roomnumber = r["room_number"]
            status = "ว่าง"
            str_timestart = "-"
            timestart = "-"
            timeusage = "-"
            str_timewait = "-"
        else:
            roomnumber = r["room_number"]
            status = "ไม่ว่าง"
            timestart = datetime.datetime.fromtimestamp(r["time_in"])
            str_timestart = timestart.strftime("%H") + ":" + timestart.strftime("%M")
            timeusage = datetime.datetime.now().timestamp() - r["time_in"]
            timeusage = int(timeusage/60)
            timewait = estime["time"]
            hr_wait = int(timewait/3600)
            min_wait = int((timewait - hr_wait*3600)/60)
            sec_wait = int(timewait - min_wait*60)
            str_timewait = str(hr_wait) + ":" + str(min_wait) + ":" + str(sec_wait) 
        ans = {"roomNumber": roomnumber, "status": status, "timeStart": str_timestart, "timeUsage": timeusage, "timeWaiting": str_timewait}
        result.append(ans)
    return {
        "result": result
    }
