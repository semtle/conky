/* -*- mode: c; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*-
 * vim: ts=4 sw=4 noet ai cindent syntax=cpp
 */

#include <config.h>

#include "nc.h"

namespace priv {
	const bool out_to_ncurses::set(const bool &r, bool init)
    {
        if(init) {
			value = r;
			if(r) {
				initscr();
				start_color();
			}
        }
		return value;
    }

	void out_to_ncurses_setting::cleanup(lua::state &l)
	{
		lua::stack_sentry s(l, -1);

		if(do_convert(l, -1).first)
			endwin();

		l.pop();
	}
}

priv::out_to_ncurses_setting out_to_ncurses;
