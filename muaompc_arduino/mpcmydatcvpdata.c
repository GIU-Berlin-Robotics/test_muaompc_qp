#include <stddef.h>  /* NULL */
#include "mpccvp.h"
real_t mpcmydat_x_bar_data[] = {0.0, 0.0};
struct mpc_term mpcmydat_x_bar = {2, 1, mpcmydat_x_bar_data};
real_t mpcmydat_H_val_data[] = {0.9978344637628452, 0.00107628641144233, 0.0007968098306571891, 0.0005262306412686228, 0.00026159123470957885, 0.00107628641144233, 0.9976622668226838, 0.0008851396484470665, 0.0005846077089576469, 0.00029063367656432637, 0.0007968098306571891, 0.0008851396484470665, 0.9974500308011854, 0.0006494711175010071, 0.00032290305640293466, 0.0005262306412686228, 0.0005846077089576469, 0.0006494711175010071, 0.9971882884821878, 0.00035875792289027724, 0.00026159123470957885, 0.00029063367656432637, 0.00032290305640293466, 0.00035875792289027724, 0.9968653435741813};
struct mpc_term mpcmydat_H_val = {5, 5, mpcmydat_H_val_data};
struct mpc_term mpcmydat_H_aux = {0, 0, NULL};
struct mpc_term mpcmydat_H_fac0 = {0, 0, NULL};
struct mpc_term **mpcmydat_H_fac = NULL;
struct mpc_term **mpcmydat_H_par = NULL;
struct mpc_pmetric mpcmydat_H;
uint32_t mpcmydat_H_fac_num = 0;
uint32_t *mpcmydat_H_par_id = NULL;
real_t mpcmydat_g_val_data[] = {0.0, 0.0, 0.0, 0.0, 0.0};
struct mpc_term mpcmydat_g_val = {5, 1, mpcmydat_g_val_data};
real_t mpcmydat_g_fac0_data[] = {0.0, 0.0, 0.0, 0.0, 0.0};
struct mpc_term mpcmydat_g_fac0 = {5, 1, mpcmydat_g_fac0_data};
real_t mpcmydat_g_aux_data[] = {0.0, 0.0, 0.0, 0.0, 0.0};
struct mpc_term mpcmydat_g_aux = {5, 1, mpcmydat_g_aux_data};
struct mpc_term *mpcmydat_g_fac[1];
struct mpc_term *mpcmydat_g_par[1];
struct mpc_pmetric mpcmydat_g;
real_t mpcmydat_g_x_bar_data[] = {0.00230163889201445, 0.06155991735820376, 0.0015166223887981612, 0.04844122993804324, 0.0008768907372814598, 0.035861265278628554, 0.0003985866987642999, 0.023682571083931223, 9.964667469107497e-05, 0.01177215361864185};
struct mpc_term mpcmydat_g_x_bar = {5, 2, mpcmydat_g_x_bar_data};
uint32_t mpcmydat_g_fac_num = 1;
uint32_t mpcmydat_g_par_id[] = {0};
real_t mpcmydat_u_lb_val_data[] = {-100.0, -100.0, -100.0, -100.0, -100.0};
struct mpc_term mpcmydat_u_lb_val = {5, 1, mpcmydat_u_lb_val_data};
struct mpc_term mpcmydat_u_lb_aux = {0, 0, NULL};
struct mpc_term mpcmydat_u_lb_fac0 = {0, 0, NULL};
struct mpc_term **mpcmydat_u_lb_fac = NULL;
struct mpc_term **mpcmydat_u_lb_par = NULL;
struct mpc_pmetric mpcmydat_u_lb;
uint32_t mpcmydat_u_lb_fac_num = 0;
uint32_t *mpcmydat_u_lb_par_id = NULL;
real_t mpcmydat_u_ub_val_data[] = {100.0, 100.0, 100.0, 100.0, 100.0};
struct mpc_term mpcmydat_u_ub_val = {5, 1, mpcmydat_u_ub_val_data};
struct mpc_term mpcmydat_u_ub_aux = {0, 0, NULL};
struct mpc_term mpcmydat_u_ub_fac0 = {0, 0, NULL};
struct mpc_term **mpcmydat_u_ub_fac = NULL;
struct mpc_term **mpcmydat_u_ub_par = NULL;
struct mpc_pmetric mpcmydat_u_ub;
uint32_t mpcmydat_u_ub_fac_num = 0;
uint32_t *mpcmydat_u_ub_par_id = NULL;
struct mpc_term mpcmydat_V_val = {0, 0, NULL};
struct mpc_term mpcmydat_V_aux = {0, 0, NULL};
struct mpc_term mpcmydat_V_fac0 = {0, 0, NULL};
struct mpc_term **mpcmydat_V_fac = NULL;
struct mpc_term **mpcmydat_V_par = NULL;
struct mpc_pmetric mpcmydat_V;
uint32_t mpcmydat_V_fac_num = 0;
uint32_t *mpcmydat_V_par_id = NULL;
struct mpc_term mpcmydat_v_lb_val = {0, 0, NULL};
struct mpc_term mpcmydat_v_lb_aux = {0, 0, NULL};
struct mpc_term mpcmydat_v_lb_fac0 = {0, 0, NULL};
struct mpc_term **mpcmydat_v_lb_fac = NULL;
struct mpc_term **mpcmydat_v_lb_par = NULL;
struct mpc_pmetric mpcmydat_v_lb;
uint32_t mpcmydat_v_lb_fac_num = 0;
uint32_t *mpcmydat_v_lb_par_id = NULL;
struct mpc_term mpcmydat_v_ub_val = {0, 0, NULL};
struct mpc_term mpcmydat_v_ub_aux = {0, 0, NULL};
struct mpc_term mpcmydat_v_ub_fac0 = {0, 0, NULL};
struct mpc_term **mpcmydat_v_ub_fac = NULL;
struct mpc_term **mpcmydat_v_ub_par = NULL;
struct mpc_pmetric mpcmydat_v_ub;
uint32_t mpcmydat_v_ub_fac_num = 0;
uint32_t *mpcmydat_v_ub_par_id = NULL;
    struct mpc_cvp_prb mpcmydat_prb;


uint32_t mpcmydat_socc_num = 0;
struct mpc_cvp_socc **mpcmydat_socc = NULL;
struct mpc_cvp_prb_socc *mpcmydat_prb_socc = NULL;


void mpcmydat_cvp_setup_former(struct mpc_cvp *cvp)
{
    cvp->par[MPC_X_BAR] = &mpcmydat_x_bar;
    cvp->pmetric[MPC_H] = &mpcmydat_H;
    cvp->pmetric[MPC_H]->fac_num = &mpcmydat_H_fac_num;
    cvp->pmetric[MPC_H]->par_id = mpcmydat_H_par_id;
    cvp->pmetric[MPC_H]->val = &mpcmydat_H_val;
    cvp->pmetric[MPC_H]->aux = &mpcmydat_H_aux;
    cvp->pmetric[MPC_H]->fac0 = &mpcmydat_H_fac0;
    cvp->pmetric[MPC_H]->par = mpcmydat_H_par;
    cvp->pmetric[MPC_H]->fac = mpcmydat_H_fac;
    cvp->pmetric[MPC_G] = &mpcmydat_g;
    cvp->pmetric[MPC_G]->fac_num = &mpcmydat_g_fac_num;
    cvp->pmetric[MPC_G]->par_id = mpcmydat_g_par_id;
    cvp->pmetric[MPC_G]->val = &mpcmydat_g_val;
    cvp->pmetric[MPC_G]->aux = &mpcmydat_g_aux;
    cvp->pmetric[MPC_G]->fac0 = &mpcmydat_g_fac0;
    cvp->pmetric[MPC_G]->par = mpcmydat_g_par;
    cvp->pmetric[MPC_G]->fac = mpcmydat_g_fac;
    cvp->pmetric[MPC_G]->fac[0] = &mpcmydat_g_x_bar;
    cvp->pmetric[MPC_G]->par[0] = &mpcmydat_x_bar;
    cvp->pmetric[MPC_U_LB] = &mpcmydat_u_lb;
    cvp->pmetric[MPC_U_LB]->fac_num = &mpcmydat_u_lb_fac_num;
    cvp->pmetric[MPC_U_LB]->par_id = mpcmydat_u_lb_par_id;
    cvp->pmetric[MPC_U_LB]->val = &mpcmydat_u_lb_val;
    cvp->pmetric[MPC_U_LB]->aux = &mpcmydat_u_lb_aux;
    cvp->pmetric[MPC_U_LB]->fac0 = &mpcmydat_u_lb_fac0;
    cvp->pmetric[MPC_U_LB]->par = mpcmydat_u_lb_par;
    cvp->pmetric[MPC_U_LB]->fac = mpcmydat_u_lb_fac;
    cvp->pmetric[MPC_U_UB] = &mpcmydat_u_ub;
    cvp->pmetric[MPC_U_UB]->fac_num = &mpcmydat_u_ub_fac_num;
    cvp->pmetric[MPC_U_UB]->par_id = mpcmydat_u_ub_par_id;
    cvp->pmetric[MPC_U_UB]->val = &mpcmydat_u_ub_val;
    cvp->pmetric[MPC_U_UB]->aux = &mpcmydat_u_ub_aux;
    cvp->pmetric[MPC_U_UB]->fac0 = &mpcmydat_u_ub_fac0;
    cvp->pmetric[MPC_U_UB]->par = mpcmydat_u_ub_par;
    cvp->pmetric[MPC_U_UB]->fac = mpcmydat_u_ub_fac;
    cvp->pmetric[MPC_V] = &mpcmydat_V;
    cvp->pmetric[MPC_V]->fac_num = &mpcmydat_V_fac_num;
    cvp->pmetric[MPC_V]->par_id = mpcmydat_V_par_id;
    cvp->pmetric[MPC_V]->val = &mpcmydat_V_val;
    cvp->pmetric[MPC_V]->aux = &mpcmydat_V_aux;
    cvp->pmetric[MPC_V]->fac0 = &mpcmydat_V_fac0;
    cvp->pmetric[MPC_V]->par = mpcmydat_V_par;
    cvp->pmetric[MPC_V]->fac = mpcmydat_V_fac;
    cvp->pmetric[MPC_V_LB] = &mpcmydat_v_lb;
    cvp->pmetric[MPC_V_LB]->fac_num = &mpcmydat_v_lb_fac_num;
    cvp->pmetric[MPC_V_LB]->par_id = mpcmydat_v_lb_par_id;
    cvp->pmetric[MPC_V_LB]->val = &mpcmydat_v_lb_val;
    cvp->pmetric[MPC_V_LB]->aux = &mpcmydat_v_lb_aux;
    cvp->pmetric[MPC_V_LB]->fac0 = &mpcmydat_v_lb_fac0;
    cvp->pmetric[MPC_V_LB]->par = mpcmydat_v_lb_par;
    cvp->pmetric[MPC_V_LB]->fac = mpcmydat_v_lb_fac;
    cvp->pmetric[MPC_V_UB] = &mpcmydat_v_ub;
    cvp->pmetric[MPC_V_UB]->fac_num = &mpcmydat_v_ub_fac_num;
    cvp->pmetric[MPC_V_UB]->par_id = mpcmydat_v_ub_par_id;
    cvp->pmetric[MPC_V_UB]->val = &mpcmydat_v_ub_val;
    cvp->pmetric[MPC_V_UB]->aux = &mpcmydat_v_ub_aux;
    cvp->pmetric[MPC_V_UB]->fac0 = &mpcmydat_v_ub_fac0;
    cvp->pmetric[MPC_V_UB]->par = mpcmydat_v_ub_par;
    cvp->pmetric[MPC_V_UB]->fac = mpcmydat_v_ub_fac;

    cvp->socc_num = &mpcmydat_socc_num;
    cvp->socc = mpcmydat_socc;
    cvp->socc_num = &mpcmydat_socc_num;


    cvp->prb = &mpcmydat_prb;
    cvp->prb->H = &mpcmydat_H_val;
    cvp->prb->g = &mpcmydat_g_val;
    cvp->prb->u_lb = &mpcmydat_u_lb_val;
    cvp->prb->u_ub = &mpcmydat_u_ub_val;

    return;
}

void mpcmydat_cvp_setup_parameters(struct mpc_cvp_parameters *parameters,
    struct mpc_cvp *cvp)
{
    parameters->x_bar = cvp->par[MPC_X_BAR]->data;

    return;
}
