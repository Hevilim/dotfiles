from fastapi import APIRouter

from pydantic import BaseModel
from typing import List

from app.db.crud import get_questions

router = APIRouter()


class 

@router.get("/quiz")
async def quiz():
    