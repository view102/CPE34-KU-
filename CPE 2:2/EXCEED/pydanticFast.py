from pymongo import MongoClient

from fastapi import FastAPI
from pydantic import BaseModel
from typing import Optional
from fastapi.encoders import jsonable_encoder

app = FastAPI()

client = MongoClient('mongodb://localhost', 27017)
db = client["Test_pymongo"]
menu_collection = db["menu"]

class Menu(BaseModel):
    name: str
    price: int
    amount: int

@app.post("/new-menu")
def add_menu(menu: Menu):
    #print(menu)
    m = jsonable_encoder(menu)
    print(m)
    menu_collection.insert_one(m)
    #menu_collection.insert_one(menu)

@app.get("/menu/{name}")
def get_menu(name: str):
    result = menu_collection.find_one({"name": name}, {"_id":0})
    print(result)
    if result != None:
        return {
            "status": "found",
            "result": result
        }
    else:
        return {
            "status": "not found"
        }
