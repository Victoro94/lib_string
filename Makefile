all:
	@echo "making all"
	@echo ""
	@make --no-print-directory -C src all

debug:
	@echo "making debug"
	@echo ""
	@make --no-print-directory -C src debug


test:
	@echo "making test"
	@echo ""
	@make --no-print-directory -C tests test


check:
	@echo "testing"
	@echo ""
	@make --no-print-directory -C tests check

docs:  Doxyfile
	@mkdir -p docs
	@rm -rf docs/*
	@doxygen Doxyfile
	@sed -i '/{text:"Macros",url:"globals_defs.html"}/d;/{text:"Typedefs",url:"globals_type.html"}/d' docs/menudata.js
	@sed -i '/\[ "Macros", "globals_defs.html", null \]/d;/\[ "Typedefs", "globals_type.html", null \]/d' docs/navtreedata.js
	@rm -f docs/globals_defs.html docs/globals_type.html

.PHONY: clean docs

clean:
	@echo "cleaning"
	@echo ""
	@make --no-print-directory -C src clean
	@echo ""
	@make --no-print-directory -C tests clean
	@echo "\ncleaning done"
