/*
 * Copyright (c) 2019 AHOHNMYC
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the COPYING file for more details.
 */

#include <locale.h>
#include <stdio.h>
#include <windows.h>

void IterateAtoms(BOOL printStats, FARPROC callback, LPCWSTR finded, LPCSTR notFound, LPCSTR xfound) {
	unsigned short a=0;
	WCHAR aStr[1000] = {0};
	unsigned short atomCount = 0;

	do
		if (callback(a, aStr, sizeof aStr) > 0) {
			if (!printStats)
				wprintf(finded, a, a, aStr);
			atomCount++;
		}
	while (++a>0);
	if (printStats) {
		if (!atomCount)
			printf(notFound);
		else
			printf(xfound, atomCount);
	}
}

void _main() {
	setlocale(LC_ALL, ""); // To print wide-char messages painless
	
	IterateAtoms( TRUE, (FARPROC)GlobalGetAtomNameW, L"Global ATOM no.%d (0x%04X) is\t\"%ws\"\n", "No one global ATOM was found :(\n", "%d global ATOM was found\n");
	IterateAtoms( TRUE, (FARPROC)      GetAtomNameW, L"Local  ATOM no.%d (0x%04X) is\t\"%ws\"\n", "No one  local ATOM was found :(\n", "%d  local ATOM was found\n");
	IterateAtoms(FALSE, (FARPROC)GlobalGetAtomNameW, L"Global ATOM no.%d (0x%04X) is\t\"%ws\"\n", "No one global ATOM was found :(\n", "%d global ATOM was found\n");
	IterateAtoms(FALSE, (FARPROC)      GetAtomNameW, L"Local  ATOM no.%d (0x%04X) is\t\"%ws\"\n", "No one  local ATOM was found :(\n", "%d  local ATOM was found\n");
}

