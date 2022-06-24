#ifndef MPCFORMQP_H
#define MPCFORMQP_H

#include "mc04types.h"  /* typedefs */
#include "arithmetic.h"

#define MPC_CVP_PRB_INPUTBOX 1
#define MPC_CVP_PRB_AFFINE 0
#define MPC_CVP_PRB_SOCC 0
#define MPC_CVP_PRB_SPARSE 0


/* Declarations that depend only on the structure of the problem
 * These are used to generate code independent of the data size
 */

enum {
    MPC_X_BAR = 0,

    MPC_PAR_NUM
};

enum {
    MPC_H,
    MPC_U_LB,
    MPC_U_UB,
    MPC_V,
    MPC_G,
    MPC_V_LB,
    MPC_V_UB,
    MPC_PMETRIC_NUM
};

enum {
    MPC_SOCC_WM,
    MPC_SOCC_WVT,
    MPC_SOCC_WN,
    MPC_SOCC_WS,
    MPC_SOCC_PMETRIC_NUM
};

struct mpc_term {
    uint32_t rows;
    uint32_t cols;
    real_t *data;
};

struct mpc_pmetric {
    uint32_t *fac_num;
    uint32_t *par_id;
    struct mpc_term *val;
    struct mpc_term *aux;
    struct mpc_term *fac0;
    struct mpc_term **fac;
    struct mpc_term **par;
};

struct mpc_cvp_socc {
    struct mpc_pmetric *pmetric[MPC_SOCC_PMETRIC_NUM];
};

struct mpc_cvp_prb_socc {
    struct mpc_term *Wm;
    struct mpc_term *wn;
    struct mpc_term *wvT;
    struct mpc_term *ws;
};

struct mpc_cvp_prb {
    struct mpc_term *H;
    struct mpc_term *g;
    struct mpc_term *u_lb;
    struct mpc_term *u_ub;

};

/* Second-order cone program in its most general form,
       for a given set of parameters p.
 * The parametric second-order cone program to be solved has the form:
 * minimize 0.5 * u^T * H * u + u^T * g
 * subject to u_lb(p) <= u <= u_ub(p)
 *            v_lb(p) <= V * u <= v_ub(p)
 *            u^T * Wq_i * u <= wr_i(p), i=1,...,n_q
 *            | Wm_j * u + wn_j(p) | <= wvT_j * u + ws_j(p), i=1,...,n_s
 *
 * the transpose of a matrix is denote by ^T.
 *H;  The Hessian matrix.
 *g;  The gradient vector.
 *u_lb;   The lower bound for the box constraints.
 *u_ub;   The upper bound for the box constraints.
 *V;   The mixed constraints matrix.
 *v_lb;   The lower bound for the mixed constraints.
 *v_ub;   The upper bound for the mixed constraints.
 * TODO: update info
 */

struct mpc_cvp {
    struct mpc_term *par[MPC_PAR_NUM];
    struct mpc_pmetric *pmetric[MPC_PMETRIC_NUM];
    uint32_t *socc_num;
    struct mpc_cvp_socc **socc;
    struct mpc_cvp_prb *prb;
};

struct mpc_cvp_parameters {
    real_t *x_bar;

};

extern void mpc_cvp_copy_parameters(struct mpc_cvp *cvp, struct mpc_cvp_parameters *p);
extern void mpc_cvp_form_problem(struct mpc_cvp *cvp);

#endif
