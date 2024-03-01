all: mainSnake

mainSnake: mainSnake.o libUI.a libRecord.a libControl.a libLogic.a
	gcc -o snake mainSnake.o -L./UI -lUI -L./record -lRecord -L./Control -lControl -L./Logic -lLogic

mainSnake.o: mainSnake.c
	gcc -c mainSnake.c

libUI.a:
	$(MAKE) -C UI

libRecord.a:
	$(MAKE) -C record

libControl.a:
	$(MAKE) -C Control

libLogic.a:
	$(MAKE) -C Logic

clean:
	rm -f mainSnake mainSnake.o
	$(MAKE) -C UI clean
	$(MAKE) -C record clean
	$(MAKE) -C Control clean
	$(MAKE) -C Logic clean

.PHONY: all clean libUI.a libRecord.a libControl.a libLogic.a
