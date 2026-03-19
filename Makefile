

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

.PHONY: clean

clean:
	@echo "cleaning"
	@echo ""
	@make --no-print-directory -C src clean
	@echo ""
	@make --no-print-directory -C tests clean
