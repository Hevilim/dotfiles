from fastapi import APIRouter

from app.api.routes import greet, signup, webhook, login, protected, quiz

api_router = APIRouter()
api_router.include_router(webhook.router)
api_router.include_router(protected.router)
api_router.include_router(greet.router)
api_router.include_router(signup.router)
api_router.include_router(login.router)
api_router.include_router(quiz.router)
