bin_PROGRAMS = shxcalc test_shx
shxcalc_SOURCES = main.cpp ShxCalculator.cpp ShxCalculator.h
test_shx_SOURCES = test_shx.cpp ShxCalculator.cpp ShxCalculator.h

install-exec-hook:
	mkdir -p $(DESTDIR)/usr/bin
	cp shxcalc $(DESTDIR)/usr/bin/shxcalc
