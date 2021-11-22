import pygame as pg
import random
from os import path

from pygame import key

img_dir = path.join('source/img')
font_name = pg.font.match_font('arial')

# define screen resolution [width 480 , height 600 , FPS 60 ]
width = 480
height = 600
FPS = 60
# define colors
white = (255, 255, 255)
black = (0, 0, 0)

# initialize pg and create window
pg.init()
screen = pg.display.set_mode((width, height))
pg.display.set_caption("ShipSpace!")
clock = pg.time.Clock()

# load game graphics
bg = pg.image.load(path.join(img_dir, "space.png")).convert()
bg_rect = bg.get_rect()
ship_img = pg.image.load(path.join(img_dir, "Ship.png")).convert()
meteor_img = pg.image.load(path.join(img_dir, "meteor_med.png")).convert()
meteor_big_img = pg.image.load(path.join(img_dir, "meteor_big.png")).convert()
bullet_img = pg.image.load(path.join(img_dir, "red_bullet.png")).convert()
ball_img = pg.image.load(path.join(img_dir, "intro_ball.gif")).convert_alpha()

#################################################################################################
# Class ที่เพิ่มเข้ามาใหม่ -> Ship , Meteor , Bullet ; Function ที่เพิ่มเข้ามาใหม่ -> newmeteor()

# Class ของผู้เล่นภายในมี method __init__ , update , shoot


class Ship(pg.sprite.Sprite):
    def __init__(self):
        pg.sprite.Sprite.__init__(self)
        self.image = pg.transform.scale(ship_img, (50, 38))
        self.image.set_colorkey(black)
        self.rect = self.image.get_rect()
        self.rect.centerx = width / 2
        self.rect.bottom = height - 10
        self.speedx = 0

    def update(self):
        self.speedx = 0
        keystate = pg.key.get_pressed()
        if keystate[pg.K_LEFT]:
            self.speedx = -8
        if keystate[pg.K_RIGHT]:
            self.speedx = 8
        self.rect.x += self.speedx
        if self.rect.right > width:
            self.rect.right = width
        if self.rect.left < 0:
            self.rect.left = 0

    def shoot(self):
        bullet = Bullet(self.rect.centerx, self.rect.top)
        all_sprites.add(bullet)
        bullets.add(bullet)

# Class ของของหินภายในมี method __init__ , update


class Meteor(pg.sprite.Sprite):
    def __init__(self, lives):
        pg.sprite.Sprite.__init__(self)
        if lives == 1:
            self.image = meteor_img
        elif lives == 2:
            self.image = meteor_big_img
        self.image.set_colorkey(black)
        self.rect = self.image.get_rect()
        self.rect.x = random.randrange(width - self.rect.width)
        self.rect.y = random.randrange(-100, -40)
        if lives == 1:
            self.speedy = random.randrange(3, 7)
        elif lives == 2:
            self.speedy = random.randrange(1, 4)
        self.speedx = random.randrange(-3, 3)
        self.lives = lives

    def update(self):
        self.rect.x += self.speedx
        self.rect.y += self.speedy
        if self.rect.top > height + 10 or self.rect.left < -25 or self.rect.right > width + 20:
            self.rect.x = random.randrange(width - self.rect.width)
            self.rect.y = random.randrange(-100, -40)
            self.speedy = random.randrange(1, 8)

# Class ของลูกกระสุนภายในมี method __init__ , update


class Bullet(pg.sprite.Sprite):
    def __init__(self, x, y):
        pg.sprite.Sprite.__init__(self)
        self.image = bullet_img
        self.image.set_colorkey(black)
        self.rect = self.image.get_rect()
        self.rect.bottom = y
        self.rect.centerx = x
        self.speedy = -10

    def update(self):
        self.rect.y += self.speedy
        # ทำลายลูกกระสุนทิ้งถ้าลูกกระสุนออกจากหน้าจอ
        if self.rect.bottom < 0:
            self.kill()

# function ที่สร้างหินขึ้นมา 1 ก้อน


def newmeteor(lives):
    m = Meteor(lives)
    all_sprites.add(m)
    meteors.add(m)


def newball():
    b = Ball()
    all_sprites.add(b)
    balls.add(b)
#################################################################################################


class Ball(pg.sprite.Sprite):
    def __init__(self):
        pg.sprite.Sprite.__init__(self)
        self.image = ball_img
        self.image = pg.transform.scale(self.image, (50, 50))
        self.image.set_colorkey(black)
        self.rect = self.image.get_rect()
        self.rect.x = random.randrange(width - self.rect.width)
        self.rect.y = random.randrange(-100, -40)
        self.speedy = random.randrange(1, 4)
        self.speedx = random.randrange(-3, 3)

    def update(self):
        self.rect.x += self.speedx
        self.rect.y += self.speedy
        if self.rect.top > height + 10 or self.rect.left < -25 or self.rect.right > width + 20:
            self.rect.x = random.randrange(width - self.rect.width)
            self.rect.y = random.randrange(-100, -40)
            self.speedy = random.randrange(1, 8)


new_game = True
high_score = 0
while True:

    # set ให้ตัวเกมส์แสดงผลด้วยความเร็วที่เหมาะสม
    clock.tick(FPS)

    if new_game:
        new_game = False
        score = 0

        #################################################################################################
        # TO DO 1-1 : สรา้ง sprite Group ให้กับ all_sprites, meteors, bullets, ship

        all_sprites = pg.sprite.Group()
        meteors = pg.sprite.Group()
        bullets = pg.sprite.Group()
        balls = pg.sprite.Group()
        ships = pg.sprite.Group()

        # TO DO 1-2 : สร้าง Object ให้กับ ship
        ship = Ship()
        ships.add(ship)
        # TO DO 1-3 : เพิ่ม ship ลงใน all_sprites
        all_sprites.add(ship)

        #################################################################################################
        # TO DO 2 : สร้าง Object Meteor ขึ้นมา 8 ก้อนโดยผ่านการเรียกใช้ฟังก์ชัน newmeteor()
        for i in range(8):
            newmeteor(random.randrange(1, 3))

        #################################################################################################

    for event in pg.event.get():
        if event.type == pg.QUIT:
            pg.quit()
        #################################################################################################
        # TO DO 3 : ตรวจสอบว่าถ้ามีการกดปุ่ม spacebar (K_SPACE) ให้ ship เรียกฟังก์ชั่นสำหรับการยิงกระสุน
        keystate = pg.key.get_pressed()
        if keystate[pg.K_SPACE]:
            ship.shoot()

        #################################################################################################

    # Update
    all_sprites.update()

    #################################################################################################
    # TO DO 5 : ตรวจสอบว่าลูกกระสุนชนหินหรือไม่
    # ถ้าชนให้สร้างหินขึ้นมาใหม่เท่ากับจำนวนที่ถูกชนไป
    hits = pg.sprite.groupcollide(meteors, bullets, False, True)
    for hit in hits:
        hit.lives -= 1
        if hit.lives == 0:
            all_sprites.remove(hit)
            meteors.remove(hit)
            hit.kill()
            newmeteor(random.randrange(1, 3))
            if random.randrange(1, 101) <= 6:
                newball()
            score += 1

    hits = pg.sprite.groupcollide(balls, ships, True, False)
    if hits:
        score += 20
        for meteor in meteors:
            meteors.remove(meteor)
            all_sprites.remove(meteor)
            meteor.kill()
        for i in range(8):
            newmeteor(random.randrange(1, 3))
    #################################################################################################
    # TO DO 6 : ตรวจสอบว่าหินชนยานผู้เล่นหรือไม่
    # ถ้าชนให้เริ่มเกมใหม่
    hits = pg.sprite.spritecollide(ship, meteors, True)
    if hits:
        high_score = max(score, high_score)
        new_game = True

    #################################################################################################
    # TO DO 4 : clear screen ด้วยสีดำ จากนั้น เอา bg ใส่ใน bg_rect
    screen.fill(black)
    screen.blit(bg, bg_rect)
    #################################################################################################
    # TO DO 7 : วาด element ใน all_sprites ลงใน screen
    all_sprites.draw(screen)
    #################################################################################################
    # show score
    font = pg.font.Font(font_name, 20)
    text_surface = font.render('Score: ' + str(score), True, white)  # กำหนด Text และ สี
    text_rect = text_surface.get_rect()  # แปลง Surface เป็น object
    text_rect.topright = (width, 0)  # ระบุตำแหน่งของ text
    screen.blit(text_surface, text_rect)  # เอา Text ใส่ลงใน object ของ Text นั้น

    # show high score
    font = pg.font.Font(font_name, 30)
    text_surface = font.render('High Score: ' + str(high_score), True, white)  # กำหนด Text และ สี
    text_rect = text_surface.get_rect()  # แปลง Surface เป็น object
    text_rect.topleft = (0, 0)  # ระบุตำแหน่งของ text
    screen.blit(text_surface, text_rect)  # เอา Text ใส่ลงใน object ของ Text นั้น

    # after drawing everything, flip the display
    pg.display.flip()

pg.quit()
