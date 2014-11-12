#-*-coding:utf-8-*-
import web
import os

urls = (
    '/', 'hello',
    '/motor', 'motor'
)
app = web.application(urls, globals())

class hello:
    def __init__(self):
        self.render = web.template.render('templates/')
    def GET(self):
        return self.render.demo()
		
class motor:
    def __init__(self):
	global fp
	fp = open("/tmp/fifo", "w")

    def GET(self):
		return 'hello world'
		#return self.render.form()

    def POST(self):
		para = web.input()
		dx = para['dx']
		dy = para['dy']
		direction = para['direction']
		if direction == 'right':
			fp.write('r___')
		elif direction == 'left':
			fp.write('l___')
		elif direction == 'up':
			fp.write('u___');
		elif direction == 'down':
			fp.write('d___');
		#fp.write("hell");
		#print 'dx : ', dx
		#print 'dy : ', dy
		print 'direction : ', direction

if __name__ == '__main__':
    app.run()
