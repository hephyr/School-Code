#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os
import socket

import telegram
from telegram.ext import Updater
from telegram.ext import MessageHandler, Filters, CommandHandler

updater = Updater(token='200092971:AAHYRnWGp-LvLJBLudgCZ4OC_Ihrct4Z01k')
dispatcher = updater.dispatcher


def openDoor(bot, update):
    bot.sendChatAction(chat_id=update.message.chat_id,
                       action=telegram.ChatAction.TYPING)
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(('127.0.0.1', 22000))
    s.close()
    bot.sendMessage(chat_id=update.message.chat_id, text='open')

open_door_handler = CommandHandler('open', openDoor)
dispatcher.add_handler(open_door_handler)
updater.start_polling()
