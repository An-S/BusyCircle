#define compiler flags for cc65 as well as gcc
cc65flags = -O $(addprefix -I, $(cbmincdirs))\
			 -D CBM_TARGET
cl65flags = -c -l $(basename $<).lst $(cc65flags) $(addprefix -Wa -I, $(cbmincdirs))
ccflags := -c -O -g --std=gnu11 -fplan9-extensions $(shell /usr/local/bin/sdl2-config --cflags)
ld65flags = -Ln $(cbmdir)/src/$(exebasename).lbl -m $(cbmdir)/src/$(exebasename).map \
			-L $(cbmlibdir)
ldflags := $(shell /usr/local/bin/sdl2-config --static-libs)
exebasename = busycircle

#define basedirs for sources
cbmbasedir = /home/mc78/Coding_64
cbmdir = ./cbm
linuxdir = ./linux
windir = ./win
sharedir = ./share
testdir = ./tests
sdldir = /usr/include/SDL2
sdllibdir = /usr/lib/x86_64-linux-gnu/
cbmlibdir = /home/mc78/Coding_64/lib

#get lists of source and header files for all targets
cbmtargets = $(wildcard $(cbmdir)/src/*.c) $(wildcard $(cbmdir)/src/*.s)
cbmtests = $(wildcard $(cbmdir)/testsrc/*.c)
linuxtargets = $(wildcard $(linuxdir)/src/*.c)
sharetargets = $(wildcard $(sharedir)/src/*.c)
sharetests = $(wildcard $(sharedir)/testsrc/*.c)
sdltargets = $(wildcard $(sharedir)/SDL/src/*.c)

cbmheads = $(wildcard $(cbmdir)/include/*.h)
linuxheads = $(wildcard $(linuxdir)/include/*.h)
shareheads = $(wildcard $(sharedir)/include/*.h)
sdlheads = $(wildcard $(sharedir)/SDL/include/*.h)

#set libraries to link
cbmlibs = carlos.lib
#get object file names from source file names
cbmobjs = $(patsubst $(cbmdir)/src/%.s, $(cbmdir)/obj/%.o, \
			$(patsubst $(cbmdir)/src/%.c, $(cbmdir)/obj/%.o, $(cbmtargets)) ) \
		  $(patsubst $(sharedir)/obj%, $(sharedir)/cbmobj%, $(shareobjs))

cbmtestprgs = $(patsubst $(cbmdir)/testsrc/%.c, $(testdir)/cbm/%.prg, $(cbmtests))\
				$(patsubst $(sharedir)/testsrc/%.c, $(testdir)/cbm/%.prg, $(sharetests))

linuxobjs = $(patsubst $(linuxdir)/src/%.c, $(linuxdir)/obj/%.o, $(linuxtargets)) \
			$(sharedir)/obj/calcsin.o $(sharedir)/obj/sintable.o
shareobjs = $(patsubst $(sharedir)/src/%.c, $(sharedir)/obj/%.o, $(sharetargets))
sharetestobjs = $(patsubst $(sharedir)/testsrc/%.c, $(sharedir)/testobj/%.o, $(sharetargets))
sdlobjs = $(patsubst $(sharedir)/SDL/src/%.c, $(sharedir)/SDL/obj/%.o, $(sdltargets))

shareincdirs = ../MCLib
cbmincdirs = $(cbmbasedir)/include $(cbmdir)/include $(sharedir)/include $(shareincdirs)
linuxincdirs = $(linuxdir)/include $(sharedir)/include $(sharedir)/SDL/include \
				$(shareincdirs) $(sdldir)

#define directories with test code
cc65test = ./cbm/src/tests/*.o

#autorules to compile sources to objects for each target
$(cbmdir)/obj/%.o: $(cbmdir)/src/%.c $(cbmheads) $(shareheads)
	cc65 $(cc65flags) -E -tc64 -o $@.i $<
	cl65 $(cl65flags) -o $@ $<

$(cbmdir)/obj/%.o: $(cbmdir)/src/%.s
	cl65 $(cl65flags) -o $@ $<

$(testdir)/cbm/%.prg: $(cbmdir)/testsrc/%.c
	-@echo "### $< ###:"
	-cl65 $(cc65flags) $(ld65flags) -o $@ $(cbmobjs) $(cbmlibs) $<

$(sharedir)/cbmobj/%.o: $(sharedir)/src/%.c
	cc65 $(cc65flags) -E -tc64 -o $@.i $<
	cl65 $(cl65flags) -o $@ $<

$(testdir)/cbm/%.prg: $(sharedir)/testsrc/%.c
	-@echo "### $< ###:"
	-cl65 $(cc65flags) $(ld65flags) -o $@ $(cbmobjs) $(cbmlibs) $<

$(linuxdir)/obj/%.o: $(linuxdir)/src/%.c
	gcc $(ccflags) -D LINUX_TARGET $(addprefix -I, $(linuxincdirs)) -o $@ $<

$(sharedir)/obj/%.o: $(sharedir)/src/%.c
	gcc $(ccflags) -D LINUX_TARGET $(addprefix -I, $(linuxincdirs)) -o $@ $<

$(sharedir)/SDL/obj/%.o: $(sharedir)/SDL/src/%.c
	gcc $(ccflags) -D LINUX_TARGET $(addprefix -I, $(linuxincdirs)) -o $@ $<

$(sharedir)/obj/%.o: $(sharedir)/src/calcsin/%.c
	gcc $(ccflags) -D LINUX_TARGET $(addprefix -I, $(linuxincdirs)) -o $@ $<

$(sharedir)/cbmobj/%.o: $(sharedir)/src/calcsin/%.c
	cc65 $(cc65flags) -E -tc64 -o $@.i $<
	cl65 $(cl65flags) -o $@ $<


#define targets and their respective dependencies on header files
.PHONY: precalcsin
precalcsin: $(sharedir)/src/calcsin/calcsin.o $(sharedir)/src/calcsin/sintable.o
	gcc $(ccflags) -o $(testdir)/$@.exe $(sharedir)/src/calcsin/calcsin.o $(sharedir)/src/calcsin/sintable.o
share: $(shareobjs) $(shareheads)

cbm: cbmtests precalcsin
	$(testdir)/cbm/sintable.prg
	cl65 $(ld65flags) -o $(exebasename).prg $(cbmobjs) $(cbmlibs)

cbmtests: $(cbmobjs) $(cbmheads) $(shareheads) $(cbmtestprgs)

linux: share $(linuxobjs) $(sdlobjs) $(linuxheads) $(sdlheads)
	echo ldflags: $(ldflags)
	gcc -o $(exebasename)_lnx $(linuxobjs) $(shareobjs) $(sdlobjs) $(ldflags) -lSDL2_ttf

.PHONY: editcbm
editcbm:

	gedit $(cbmtargets) $(cbmheads) $(sharetargets) $(shareheads) Makefile &

.PHONY: editlinux
editlinux:
	gedit $(linuxtargets) $(linuxheads) $(sharetargets) $(shareheads) $(sdltargets) $(sdlheads) Makefile &

.PHONY: editwin
editwin:
	gedit $(wintargets) $(winheads) $(sharetargets) $(shareheads) $(sdltargets) $(sdlheads) Makefile &

.PHONY: printvars
printvars:
	@echo "*** CBM targets: $(cbmtargets) ***"
	@echo "*** CBM objects: $(cbmobjs) ***"
	@echo "*** CBM heads: $(cbmheads) ***"
	@echo "*** LINUX targets: $(linuxtargets) ***"
	@echo "*** LINUX objects: $(linuxobjs) ***"
	@echo "*** SHARE targets: $(sharetargets) ***"
	@echo "*** SHARE objects: $(shareobjs) ***"
	@echo "*** SHARE heads: $(shareheads) ***"
	@echo "*** SDL targets: $(sdltargets) ***"
	@echo "*** SDL objects: $(sdlobjs) ***"
	@echo "*** CBM tests: $(cbmtests) ***"
	@echo "*** SHARE tests: $(sharetests) ***"
	@echo "*** CBM testprgs: $(cbmtestprgs) ***"
	@echo "*** CBM libs: $(cbmlibs) ***"
#target to cleanup objects and other files
.PHONY: clean
clean:
	-rm -fr "*.o" $(linuxobjs) $(cbmobjs) $(shareobjs) $(sdlobjs) $(cbmtestprgs)
	-rm -R *.prg
#batch build targets
.PHONY: all
all:	cbm linux share

#for eventual usage of makedepend
# DO NOT DELETE
