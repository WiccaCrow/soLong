# soLong. RU / EN
___________________________________________________________________RU

ОПИСАНИЕ
Этот проект представляет собой небольшую 2D-игру и основу для 2D-игры.
Он создан для обучения работе с текстурами и спрайтами. 
И некоторым очень простые элементы игрового процесса.

Чтобы запустить игровую версию, выберите в РУКОВОДСТВЕ правила с 
командой в терминале «make bonus».

Описание каждой функции в проекте приводится в
соответствующиx файлax (см. SoLong.h).
________________________________________________EN

DESCRIPTION

This project is a small 2D game and base for 2D game. 
It is built to make work with textures, sprites. 
And some very basic gameplay elements.

To start game version run "make bonus".

The header SoLong.h shows the structure of this project.

For each function in the project, a description is made in the 
appropriate files (see SoLong.h).
_____________________________________________________________________RU

РУКОВОДСТВО ДЛЯ ЗАПУСКА ИГРЫ

Чтобы запустить игру:
1. Скачайте/клонируйте к себе весь этот репозиторий
2. В терминала перейдите в папку проекта "project"
3. В каждой части (движок и сама игра) есть README.txt 
    с подробными игструкциями. 
  Коротко:
  Для сбора движка игры используйте команду 
    make
  затем запустите игру командой 
    ./so_long ./soLong/maps/1.ber

  Для сбора игры используйте команду:
    make bonus
  затем запустите игру командой
  ./so_long ./soLong_bonus/maps/2.ber

  Выше ./so_long имя игры, а ./soLong_bonus/maps/2.ber это путь до карты.

Вы можете также самостоятельно создавать карты для большего разнообразия.
см.subject

Папка для хранения карт:
движок soLong/project/soLong/maps/
игра   soLong/project/soLong_bonus/maps/

Приятной Вам игры!!!

________________________________________________EN

GUIDE FOR RUN THE GAME

To start the game:
1. Download / clone this entire repository to yourself
2. In the terminal go to the project folder "project"
3. In each part (the engine and the game itself) there 
    is a README.txt with detailed instructions. Short:
To create the base, use the command
    make
then start the base with the command
    ./so_long ./soLong/maps/1.ber
    
To create the game, use the command:
    make bonus
then start the game with the command
    ./so_long ./soLong_bonus/maps/2.ber

Above "./so_long" is the name of the game, 
and "./soLong_bonus/maps/2.ber" is the path to the map.

You can also create maps yourself for more variety.

Card storage folder:
base        soLong/project/soLong/maps/
the game    soLong/project/soLong_bonus/maps/

Enjoy your game !!!
