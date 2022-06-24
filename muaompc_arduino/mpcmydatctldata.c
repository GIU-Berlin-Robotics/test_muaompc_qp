#include "mpcmydatcvpdata.h"
#include "mpcmydatfgmdata.h"
#include "mpcctl.h"

struct mpc_ctl mpcmydat_ctl;  /**< Problem former. */
struct mpc_cvp mpcmydat_former;  /**< Problem former. */
struct mpc_fgm mpcmydat_solver;  /**< Problem solver. */
struct mpc_cvp_parameters mpcmydat_parameters;  /**< Problem parameters. */

/* Extern function definitions */

struct mpc_ctl*  mpcmydat_ctl_setup_ctl()
{
	struct mpc_ctl *ctl = &mpcmydat_ctl;
	ctl->former = &mpcmydat_former;
	ctl->solver = &mpcmydat_solver;
	ctl->parameters = &mpcmydat_parameters;

	mpcmydat_cvp_setup_former(ctl->former);
	mpcmydat_fgm_setup_solver(ctl->solver, ctl->former->prb);
	mpcmydat_cvp_setup_parameters(ctl->parameters, ctl->former);

        ctl->u_opt = ctl->solver->u_opt;

    return &mpcmydat_ctl;    
}
