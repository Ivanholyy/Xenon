#ifndef CVAR_H
#define CVAR_H 1

#include <stdio.h>

typedef struct cvar_s {
	char *name;
	char *string;
	bool archive; // saves all variables to cvar.txt
	bool server; // notifies players when changed
	float value;
	struct cvar_s *next;
} cvar_t;

void cvar_registervariable(cvar_t *variable);
void cvar_set(char *var_name, char *value);
void cvar_setvalue(char *var_name, float value);
float cvar_variablevalue(char *var_name);
char *cvar_variablestring(char *var_name);
char *cvar_completevariable(char *partial);
void cvar_writevariables(FILE *f);
cvar_t *cvar_findvar(char *var_name);

extern cvar_t *cvar_vars;

#endif
