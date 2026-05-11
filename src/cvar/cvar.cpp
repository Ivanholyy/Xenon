#include "cvar.h"
#include <string.h>
#include <stdlib.h>
#include "../log/log.h"

cvar_t *cvar_vars;
char *cvar_null_string = "";

cvar_t *cvar_findvar(char *var_name) {

	cvar_t *var;

	for (var = cvar_vars; var; var = var->next)
		if (!strcmp(var_name, var->name))
			return var;

	return NULL;
}

float cvar_variablevalue(char *var_name) {

	cvar_t *var;

	var = cvar_findvar(var_name);

	if (!var)
		return 0;

	return atof(var->string);
}

char *cvar_variablestring(char *var_name) {

	cvar_t *var;

	var = cvar_findvar(var_name);

	if (!var)
		return cvar_null_string;

	return var->string;
}

char *cvar_completevariable(char *partial) {

	cvar_t *cvar;
	int	len;

	len = strlen(partial);

	if (!len)
		return NULL;

	for (cvar = cvar_vars; cvar; cvar = cvar->next)
		if (!strncmp(partial, cvar->name, len))
			return cvar->name;

	return NULL;
}

void cvar_set(char *var_name, char *value) {

	cvar_t *var;
	bool changed;

	var = cvar_findvar(var_name);

	std::string buf = std::string("Variable ") + var_name + " not found";

	if (!var) {
		Log(buf, __LINE__, __FILE__, __PRETTY_FUNCTION__, __DATE__, __TIME__);
		return;
	}

	changed = strcmp(var->string, value);

	free(var->string);

	var->string = (char*)malloc(strlen(value) + 1);

	strcpy(var->string, value);

	var->value = atof(var->string);

	// TODO: Add server.
	/*if (var->server && changed) {
		if (sv.active)
			sv_broadcast("\"%s\" changed to \"%s\"\n", var->name, var->string);
	}*/
}

void cvar_setvalue(char *var_name, float value) {

	char val[32];

	sprintf(val, "%f", value);
	cvar_set(var_name, val);
}

void cvar_registervariable(cvar_t *variable) {

	char *oldstr;

	std::string buf = std::string("Can't register variable ") + variable->name + ", already defined";

	std::string buf1 = variable->name + std::string("is a command");

	if (cvar_findvar(variable->name)) {
		Log(buf, __LINE__, __FILE__, __PRETTY_FUNCTION__, __DATE__, __TIME__);
		return;
	}

	// TODO: Console support.
	/*if (cmd_exists(variable->name)) {
		Log(buf1, __LINE__, __FILE__, __PRETTY_FUNCTION__, __DATE__, __TIME__);
		return;
	}*/

	oldstr = variable->string;

	variable->string = (char*)malloc(strlen(variable->string) + 1);

	strcpy(variable->string, oldstr);

	variable->value = atof(variable->string);

	variable->next = cvar_vars;
	cvar_vars = variable;
}

void cvar_writevariables(FILE *f) {

	cvar_t *var;

	for (var = cvar_vars; var; var = var->next)
		if (var->archive)
			fprintf (f, "%s \"%s\"\n", var->name, var->string);
}
