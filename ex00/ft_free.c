#include "ft.h"

void	ft_free(t_keyvalue *dict)
{
	if (!dict)
		return ;
	free(dict->key);
	free(dict->value);
	ft_free(dict->next);
	free(dict);
}
