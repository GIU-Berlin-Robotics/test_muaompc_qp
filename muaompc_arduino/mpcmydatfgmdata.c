#include "mpccvp.h"
#include "mpcfgm.h"

real_t mpcmydat_nu = 0.0008548214808107899;
uint32_t mpcmydat_optvar_veclen = 1;

struct mpc_fgm_conf mpcmydat_fgm_conf = {1, 0};

real_t mpcmydat_u_opt[] = {0.0, 0.0, 0.0, 0.0, 0.0};
real_t mpcmydat_u_ini[] = {0.0, 0.0, 0.0, 0.0, 0.0};
real_t mpcmydat_fgm_tmp1_optvar_seqlen[] = {0.0, 0.0, 0.0, 0.0, 0.0};
real_t mpcmydat_fgm_tmp2_optvar_seqlen[] = {0.0, 0.0, 0.0, 0.0, 0.0};
real_t mpcmydat_fgm_tmp3_optvar_seqlen[] = {0.0, 0.0, 0.0, 0.0, 0.0};
real_t mpcmydat_fgm_tmp4_optvar_seqlen[] = {0.0, 0.0, 0.0, 0.0, 0.0};
real_t mpcmydat_fgm_tmp5_optvar_seqlen[] = {0.0, 0.0, 0.0, 0.0, 0.0};
real_t mpcmydat_fgm_tmp6_optvar_seqlen[] = {0.0, 0.0, 0.0, 0.0, 0.0};

void mpcmydat_fgm_setup_solver(
                struct mpc_fgm *fgm,
                struct mpc_cvp_prb *prb)
{
    fgm->goL = prb->g->data;
    fgm->HoL = prb->H->data;
    fgm->u_lb = prb->u_lb->data;
    fgm->u_ub = prb->u_ub->data;
    fgm->optvar_seqlen = prb->u_lb->rows;
    fgm->sizeof_optvar_seqlen = sizeof(real_t) * prb->u_lb->rows;

    fgm->nu = &mpcmydat_nu;
    fgm->optvar_veclen = mpcmydat_optvar_veclen;

    fgm->conf = &mpcmydat_fgm_conf;
    fgm->j_in = &(fgm->conf->in_iter);

    fgm->u_opt = mpcmydat_u_opt;
    fgm->u_ini = mpcmydat_u_ini;
    fgm->tmp1_optvar_seqlen = mpcmydat_fgm_tmp1_optvar_seqlen;
    fgm->tmp2_optvar_seqlen = mpcmydat_fgm_tmp2_optvar_seqlen;
    fgm->tmp3_optvar_seqlen = mpcmydat_fgm_tmp3_optvar_seqlen;
    fgm->tmp4_optvar_seqlen = mpcmydat_fgm_tmp4_optvar_seqlen;
    fgm->tmp5_optvar_seqlen = mpcmydat_fgm_tmp5_optvar_seqlen;
    fgm->tmp6_optvar_seqlen = mpcmydat_fgm_tmp6_optvar_seqlen;

    return;
}
