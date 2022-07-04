from pymongo import MongoClient

client = MongoClient('mongodb://localhost',27017)

# db = client["DATABASE"]
# menu_collection = db["COLLECTION NAME"]
db = client["Test_pymongo"]
menu_collection = db["menu"]

#mylist = client.list_database_names()

#print(mylist)

orange = {
    "name": "Orange",
    "price": 40
}

banana = {
    "name": "Banana",
    "price": 20
}

# menu_collection.insert_one(orange)
# menu_collection.insert_one(banana)

# fruit_list = []
# fruit_list.append(orange)
# fruit_list.append(banana)

# x = menu_collection.insert_many(fruit_list)
# print(x.inserted_ids)

# result = menu_collection.find_one()
# print(result)

# r = menu_collection.find({},{"_id": 0, "name": 1, "price": 1})
# for fruit in r:
#     print(fruit)

#query = {"name": "Orange", "price": 40}
#result = menu_collection.find(query, {"_id": 0, "name": 1})
#for r in result:
#    print(r)
#result = menu_collection.find_one(query)
#print(result)

#query = {"name": "Chicken"}
#menu_collection.delete_many(query)

query = {"name": "Grape"}
newvalues = { "$set": {"price": 90}}

menu_collection.update_one(query, newvalues)
menu_collection.update_many(query, newvalues)