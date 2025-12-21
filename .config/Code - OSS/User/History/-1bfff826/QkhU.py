from fastapi import APIRouter

from pydantic import BaseModel
from typing import List

from app.db.crud import get_questions

router = APIRouter()


class SubjectSchema(BaseModel):
    subject_id: int


class AnswerSchema(BaseModel):
    id: int
    text: str

class QuestionSchema(BaseModel):
    id: int
    text: str
    answers: List[AnswerSchema]


class QuizSchema(BaseModel):
    


@router.get("/quiz/{subject_id}", response_model=List[QuestionSchema])
async def quiz(subject_id: SubjectSchema):
    questions = get_questions(subject_id)

    return questions
