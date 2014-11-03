#include <libconfig.h>
#include <stdio.h>

int main(){
	config_t cfg;
	config_setting_t *setting;
	const char *str;
	int value;

	config_init(&cfg);

	config_read_file(&cfg, "board.cfg");
	config_lookup_string(&cfg, "title", &str);
	config_lookup_int(&cfg, "Board.[0].Port", &value);
	printf("%s\n", str);
	printf("%d\n", value);
	
	config_destroy(&cfg);

	return 0;
}

