from app.db.core import Base
from sqlalchemy import ForeignKey
from sqlalchemy.
from sqlalchemy.orm import Mapped, mapped_column, relationship

 
class Subject(Base):
    __tablename__ = "subjects"

    id: Mapped[int] = mapped_column(primary_key=True, index=True)
    subject_name: Mapped[str] = mapped_column()



class Question(Base):
    __tablename__ = "questions"

    id: Mapped[int] = mapped_column(primary_key=True, index=True)
    question_type: Mapped[str] = mapped_column()
    question_text: Mapped[str] = mapped_column()

    subject_id: Mapped[int] = mapped_column(ForeignKey("subjects.id"))

    subject: Mapped["Subject"] = relationship(back_populates="questions")

    answers: Mapped[list["Answer"]] = relationship(back_populates="question")


class Answer(Base): 
    __tablename__ = "answers"

    id: Mapped[int] = mapped_column(primary_key=True, index=True)
    answer_text: Mapped[str] = mapped_column()
    is_correct: Mapped[bool] = mapped_column(default=False)

    question_id: Mapped[int] = mapped_column(ForeignKey("questions.id"))

    question: Mapped["Question"] = relationship(back_populates="answers")


class Quiz(Base):
    __tablename__ = "quiz"

    id: Mapped[int] = mapped_column(primary_key=True, index=True)
    questions: Mapped[list[int]] = mapped_column()