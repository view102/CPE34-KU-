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

@app.get("/toilet/get-info")
def get_status():
    room1 = collection.find_one({"room_number": 1},{"_id": 0})
    room2 = collection.find_one({"room_number": 2},{"_id": 0})
    room3 = collection.find_one({"room_number": 3},{"_id": 0})
    estime = collection.find_one({"estimate": "estimate"},{"_id": 0})
    list_room = list()
    result = list()
    list_room.append(room1)
    list_room.append(room2)
    list_room.append(room3)
    for r in list_room:
        if(r["close"] == 0):
            roomnumber = r["room_number"]
            status = "ว่าง"
            str_timestart = "-"
            timestart = "-"
            timeusage = "-"
            timewait = "-"
        else:
            roomnumber = r["room_number"]
            status = "ไม่ว่าง"
            timestart = datetime.datetime.fromtimestamp(r["time_in"])
            str_timestart = timestart.strftime("%H") + ":" + timestart.strftime("%M")
            timeusage = datetime.datetime.now().timestamp() - r["time_in"]
            timeusage = int(timeusage/60)
            timewait = int(estime["time"])
        ans = {"roomNumber": roomnumber, "status": status, "timeStart": str_timestart, "timeUsage": timeusage, "timeWaiting": timewait}
        #print(ans)
        result.append(ans)
    return {
        "result": result
    }
"""
@app.get("/toilet/estimate")
def get_estimate():
    search = collection.find_one({"name": "Estimate2"},{"_id": 0, "estime": 1, "n": 1})
    return {
        "n": search["n"] + 1
    }

@app.put("/toilet/update")
def update_toilet(toilet: toilet_c):
    time = datetime.now()
    timein = time.strftime("%H") + ":" + time.strftime("%M") + ":" + time.strftime("%S")
    collection.update_one({"room": toilet.room},{"$set": {"time_in": timein}})
    return "SUCCESS"

@app.put("/toilet/update/estime")
def update_estime(toilet: toilet_c):
    pass
"""