from fastapi import APIRouter

from pydantic import BaseModel
from typing import List

from app.db.crud import get_questions

router = APIRouter()


class AnswerSchema(BaseModel):
    id: int
    answer_text: str


class QuestionSchema(BaseModel):
    id: int
    question_text: str
    answers: List[AnswerSchema]


# class QuizSchema(BaseModel):
#     quiz: 


@router.get("/quiz/{subject_id}", response_model=List[QuestionSchema])
async def quiz(subject_id: int):
    questions = await get_questions(subject_id)

    return questions
