#ifndef MPCCTL_H
#define MPCCTL_H

#include "mpcfgm.h"
#include "mpccvp.h"

struct mpc_ctl {
struct mpc_cvp_parameters *parameters;  /**< Problem parameters. */
struct mpc_cvp *former;  /**< Problem former. */
struct mpc_fgm *solver;  /**< Problem solver. */

real_t *u_opt;  /**< Optimal control input sequence. */
};  /**< The main MPC structure. Contains algorithm, system and runtime data. */

extern void mpc_ctl_form_problem(struct mpc_ctl *ctl);
extern void mpc_ctl_solve_problem(struct mpc_ctl *ctl);

#endif /* MPCCTL_H */
