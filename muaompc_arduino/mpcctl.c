#include "mpcctl.h"

void mpc_ctl_form_problem(struct mpc_ctl *ctl)
{
  mpc_cvp_form_problem(ctl->former);
  return;
}

void mpc_ctl_solve_problem(struct mpc_ctl *ctl)
{
  mpc_cvp_copy_parameters(ctl->former, ctl->parameters);
  mpc_cvp_form_problem(ctl->former);
  mpc_fgm_solve_problem(ctl->solver);
  return;
}

