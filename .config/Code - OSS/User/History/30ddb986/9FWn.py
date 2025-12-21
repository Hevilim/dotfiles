from app.db.core import Base
from app.db.models.subject import Subject

from sqlalchemy import ForeignKey
from sqlalchemy.dialects.postgresql import ARRAY
from sqlalchemy.orm import Mapped, mapped_column


class Question(Base):
    __tablename__ = "questions"

    id: Mapped[int] = mapped_column(primary_key=True, index=True)
    question_text: Mapped[str] = mapped_column()


class SubjectQuestions(Base):
    __tablename__ = "subject_questions"

    subject_id: Mapped[int] = mapped_column(ForeignKey("subjects.id"), primary_key=True)
    question_id: Mapped[int] = mapped_column(ForeignKey("questions.id"), primary_key=True)


class Answer(Base): 
    __tablename__ = "answers"

    id: Mapped[int] = mapped_column(primary_key=True, index=True)
    answer_text: Mapped[str] = mapped_column()
    is_correct: Mapped[bool] = mapped_column(default=False)


class QuestionAnswers(Base):
    __tablename__ = "question_answers"

    question_id: Mapped[int] = mapped_column(ForeignKey("questions.id"), primary_key=True)
    answer_id: Mapped[int] = mapped_column()


class Quiz(Base):
    __tablename__ = "quiz"

    id: Mapped[int] = mapped_column(primary_key=True, index=True)
    questions: Mapped[list[int]] = mapped_column(ARRAY(Integer))
