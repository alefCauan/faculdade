from typing import Optional, Union
from random import randrange
from fastapi import FastAPI, status, Response, HTTPException
from fastapi.params import Body
from pydantic import BaseModel

app = FastAPI()

class Post_a(BaseModel):
    title: str
    content: str
    published: bool = True
    rating: Optional[int] = None



my_post = [{"title":"title of post", "content":"Conteudo 1 ", "id": 1}, {"title": "Favortite food", "content":"pizza", "id": 2}, {"title":"Favorite anime", "content":"Shingeki no Yeager", "id": 3}]


def find_post(id):
    for p in my_post:
        if p['id'] == id:
            return p

def find_index_post(id):
    for i, p in enumerate(my_post):
        if p['id'] == id:
            return id

@app.get("/")
def read_root():
    return {"alef": "alezinho api"}

@app.get("/posts")
def get_posts():
    return {"Data": my_post}

@app.post("/createposts", status_code=status.HTTP_201_CREATED)
def create_posts(post: Post_a):
    post_dict = post.dict()
    post_dict['id'] = randrange(0, 1000000)

    my_post.append(post.dict())
    return {"data": post_dict}

@app.get("/posts/{id}")
def get_post(id: int):

    post = find_post(id)

    if not post:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, detail=f"post with id {id} was not found")
       
    return {"Post_detail": post}

@app.delete("/posts/{id}", status_code=status.HTTP_204_NO_CONTENT)
def delete_post(id: int):

    index = find_index_post(id);

    if index == None:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, detail=f"post to delete with id {id} does not exist")

    my_post.pop(index)

    return Response(status_code=status.HTTP_204_NO_CONTENT)

@app.put("/posts/{id}", status_code=status.HTTP_205_RESET_CONTENT)
def update_post(id: int, post: Post_a): 

    index = find_index_post(id);

    if index == None:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, detail=f"post to delete with id {id} does not exist")

    post_dict = post.dict() # Os dados inviados pelo front-end, são transformados em um dicionario tradicional do python 
    post_dict['id'] = id # É adicionado o id no dicionario
    my_post[index] = post_dict# O post com o index vai ser substituido com o novo dicionario
    return {"data": post_dict}