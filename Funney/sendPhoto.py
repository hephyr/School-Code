#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os
import json
import random
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
    if url is False:
        bot.sendChatAction(chat_id=update.message.chat_id,
                           action=telegram.ChatAction.TYPING)
        bot.sendMessage(chat_id=update.message.chat_id, text='Error')
    else:
        bot.sendChatAction(chat_id=update.message.chat_id,
                           action=telegram.ChatAction.UPLOAD_PHOTO)
        bot.sendPhoto(chat_id=update.message.chat_id, photo=url)


def cmdPhoto(bot, update, args):
    url = getUrl(args[0])
    if url is False:
        bot.sendChatAction(chat_id=update.message.chat_id,
                           action=telegram.ChatAction.TYPING)
        bot.sendMessage(chat_id=update.message.chat_id, text='Error')
    else:
        bot.sendChatAction(chat_id=update.message.chat_id,
                           action=telegram.ChatAction.UPLOAD_PHOTO)
        bot.sendPhoto(chat_id=update.message.chat_id, photo=url)


def randomPhoto(bot, update):
    base_url = 'http://gank.io/api/random/data/福利/1'
    r = requests.get(base_url)
    data = json.loads(r.text)
    img_src = data['results'][0]['url']
    url = img_src.encode()
    r = requests.get(url, stream=True)
    img = r.raw.read()
    f = open('photo.jpg', 'wb')
    f.write(img)
    f.close()
    try:
        bot.sendChatAction(chat_id=update.message.chat_id,
                           action=telegram.ChatAction.UPLOAD_PHOTO)
        bot.sendPhoto(chat_id=update.message.chat_id,
                      photo=open('photo.jpg', 'rb'))
        os.remove('photo.jpg')
    except BaseException, e:
        bot.sendChatAction(chat_id=update.message.chat_id,
                           action=telegram.ChatAction.TYPING)
        bot.sendMessage(chat_id=update.message.chat_id, text=str(e))
        bot.sendMessage(chat_id=update.message.chat_id, text=url)


def cmdRed(bot, update):
    base_url = 'http://7xqh4i.com1.z0.glb.clouddn.com/pic%s.jpg'
    i = random.randint(0, 330)
    url = base_url % str(i)
    bot.sendChatAction(chat_id=update.message.chat_id,
                       action=telegram.ChatAction.UPLOAD_PHOTO)
    bot.sendPhoto(chat_id=update.message.chat_id, photo=url)


echo_handler = MessageHandler([Filters.text,
                               Filters.photo,
                               Filters.status_update],
                              echo)
photo_handler = CommandHandler('num', cmdPhoto,  pass_args=True)
girl_random_handler = CommandHandler('girl', randomPhoto)
red_handler = CommandHandler('red', cmdRed)
dispatcher.add_handler(echo_handler)
dispatcher.add_handler(photo_handler)
dispatcher.add_handler(girl_random_handler)
dispatcher.add_handler(red_handler)
updater.start_polling()
