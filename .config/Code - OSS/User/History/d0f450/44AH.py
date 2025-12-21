from app.db.core import Base 
from sqlalchemy import BigInteger, ForeignKey
from sqlalchemy.orm import Mapped, mapped_column

 
class User(Base):
    __tablename__ = "users"

    id: Mapped[int] = mapped_column(primary_key=True, index=True)
    tg_id: Mapped[int] = mapped_column(BigInteger)
    first_name: Mapped[str] = mapped_column()
    last_name: Mapped[str] = mapped_column()


class Role(Base):
    __tablename__ = "roles"

    id: Mapped[int] = mapped_column(primary_key=True, index=True)

    role_name: Mapped[str] = mapped_column()


class Student(Base):
    __tablename__ = "students"

    id: Mapped[int] = mapped_column(primary_key=True, index=True)

    email: Mapped[str] = mapped_column()

    user_id: Mapped[int] = mapped_column(ForeignKey("users.id"))



class Teacher(Base):
    __tablename__ = "teachers"

    id: Mapped[int] = mapped_column(primary_key=True, index=True)

    user_id: Mapped[int] = mapped_column(ForeignKey("users.id"))