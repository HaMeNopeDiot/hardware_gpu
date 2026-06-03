DIPLOMA = build/diploma.pdf
PRESENTATION = build/presentation.pdf
PRES_MAIN = presentation/main.typ
DIP_MAIN = main.typ
DIP_SOURCE_FILES = *.typ

all: create_build_dir $(DIPLOMA) $(PRESENTATION)

create_build_dir:
	mkdir -p build
	
$(DIPLOMA): $(DIP_MAIN) $(DIP_SOURCE_FILES)
	typst compile $< $@;

$(PRESENTATION): $(PRES_MAIN)
	typst compile $< $@ --root presentation;

.PHONY: clean

clean:
	rm -rf build
