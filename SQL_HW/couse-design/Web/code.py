#-*- coding:utf-8 -*-
import web
from web.contrib.template import render_jinja#引入web.py对调用jinja2的模块

urls = (
    "/", "index",
)
app = web.application(urls, globals())

render = render_jinja(
    'templates',#模板存放的目录名称
    encoding = 'utf-8',#模板使用的编码
)

class index:
    def GET(self):
        return render.hello(word="Hello World")#使用模板目录下的index.html模板

if __name__ == "__main__":
    app.run()