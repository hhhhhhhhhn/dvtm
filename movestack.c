// mostly from https://github.com/micha/dvtm/blob/master/dvtm.c

static void swapnext(const char *args[]) {
	if(!sel)
		return;

	Client *c;

	for(c = sel->next; c && !isvisible(c); c = c->next);

	if(!c)
		return;

	detach(sel);
	attachafter(sel, c);
	focus(sel);
	arrange();
}

static void swapprev(const char *args[]) {
	if(!sel)
		return;

	Client *c;

	for(c = sel->prev; c && !isvisible(c); c = c->prev);

	if(!c)
		return;

	detach(c);
	attachafter(c, sel);
	focus(sel);
	arrange();
}
