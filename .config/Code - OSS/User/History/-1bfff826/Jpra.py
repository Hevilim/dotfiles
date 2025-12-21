from fastapi import APIRouter

from pydantic import BaseModel
from typing import List

from app.db.crud import get_questions

router = APIRouter()


class SubjectSchema(BaseModel):
    subject_id: int


class QuestionSchema(BaseModel):
    id: int
    text: str
    


@router.get("/quiz/{subject_id}", response_model=List[QuestionOut])
async def quiz(subject_id: SubjectSchema):
    