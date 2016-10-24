#!/usr/bin/env python
# -*- coding: utf-8 -*-
import requests
import telegram
from telegram.ext import Updater
from telegram.ext import MessageHandler, Filters, CommandHandler

updater = Updater(token='247176950:AAFaJefszLKQlqy1YpOXTA60lT8ZjZ8eQsw')
dispatcher = updater.dispatcher


def getUrl(text):
    text = text.strip()
    grade = text[:4]
    url = 'http://iplat.ujn.edu.cn/photo/%s/%s.jpg' % (grade, text)
    r = requests.get(url)
    if r.status_code == 200:
        return str(url)
    else:
        return False


def echo(bot, update):
    text = update.message.text
    url = getUrl(text)
    bot.sendChatAction(chat_id=update.message.chat_id,
                       action=telegram.ChatAction.TYPING)
    if url is False:
        bot.sendMessage(chat_id=update.message.chat_id, text='Error')
    else:
        bot.sendPhoto(chat_id=update.message.chat_id, photo=url)


def cmdPhoto(bot, update, args):
    url = getUrl(args[0])
    bot.sendChatAction(chat_id=update.message.chat_id,
                       action=telegram.ChatAction.TYPING)
    if url is False:
        bot.sendMessage(chat_id=update.message.chat_id, text='Error')
    else:
        bot.sendPhoto(chat_id=update.message.chat_id, photo=url)


echo_handler = MessageHandler([Filters.text,
                               Filters.photo,
                               Filters.status_update],
                              echo)
photo_handler = CommandHandler('num', cmdPhoto,  pass_args=True)
dispatcher.add_handler(echo_handler)
dispatcher.add_handler(photo_handler)
updater.start_polling()
