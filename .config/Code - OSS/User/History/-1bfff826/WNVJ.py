from fastapi import APIRouter

from pydantic import BaseModel
from typing import List

from app.db.crud import get_questions

router = APIRouter()


class AnswerSchema(BaseModel):
    id: int
    text: str

    class Config:
        orm_mode = True


class QuestionSchema(BaseModel):
    id: int
    text: str
    answers: List[AnswerSchema]

    class Config:
        orm_mode = True


# class QuizSchema(BaseModel):
#     quiz: 


@router.get("/quiz/{subject_id}", response_model=List[QuestionSchema])
async def quiz(subject_id: int):
    questions = await get_questions(subject_id)

    return questions
