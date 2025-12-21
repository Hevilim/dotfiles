import asyncio
import logging
from aiogram import Bot, Dispatcher


# Routers
from handlers.start import start
from handlers.help import help
from handlers.sign_up import sign_up


async def main():
    bot = Bot(token='6717716164:AAGamK6V3Ue-cOdv5hZqPI1b7p3ZBgCnpj0')
    dp = Dispatcher()

    dp.include_routers(start, help, sign_up)

    await dp.start_polling(bot)

if __name__ == '__main__':
    logging.basicConfig(level=logging.INFO)
    asyncio.run(main())
