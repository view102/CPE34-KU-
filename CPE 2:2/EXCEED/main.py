from fastapi import FastAPI
from typing import Optional
from pydantic import BaseModel

app = FastAPI()

class Item(BaseModel):
    name: str
    price: float
    discount: Optional[float] = 0

@app.get("/")
def root():
    return {"Hello": "Exceed"}

@app.post("/")
def root_post():
    return {"Hello": "Exceed from POST"}

@app.get("/items/{item_id}")
def get_item(item_id: int, q: Optional[str] = None):
    return {"item_id": item_id, "q": q}

@app.post("/items/{item_id}")
def get_item(item_id: int, item: Item):
    return {"price": item.price,
            "name": item.name, 
            "discount": item.discount}