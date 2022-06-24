#ifndef MPC_FGM_H
#define MPC_FGM_H

#include "mc04types.h"
#include "arithmetic.h"

/* Quadratic Programming online solver using Fast gradients.
 * Most of these functions are intended for internal use.
 */
struct mpc_fgm_conf {
uint32_t in_iter;  /**< Maximum number of internal loop (FGM) iterations (j_in). */
uint32_t warm_start;  /**< If not 0, automatically warm start next algorithm iteration. */
}; /**< Configuration parameters of the MPC algorithm. */

struct mpc_fgm {
struct mpc_fgm_conf *conf;  /**< Algorithm configuration data. */
real_t *u_opt;  /**< Solution to the optimal control problem. */
real_t *u_ini;  /**< Initial guess for the optimal control sequence. */
real_t *goL;  /**< Gradient vector over Lipschitz for the current system state. */
uint32_t *j_in;  /**< Maximun number of internal loop (FGM) iterations .*/
real_t *HoL;  /**< Hessian matrix of QP over Lipschitz constant. */
real_t *u_lb;  /**< Lower bound constraint of the inputs for condensed QP. */
real_t *u_ub;  /**< Upper bound constraint of the inputs for condensed QP. */
real_t *nu;  /**< Fast gradient extra step constant. */
real_t *tmp1_optvar_seqlen;  /**< Temporary variable of length optvar_seqlen. */
real_t *tmp2_optvar_seqlen;  /**< Temporary variable of length optvar_seqlen. */
real_t *tmp3_optvar_seqlen;  /**< Temporary variable of length optvar_seqlen. */
real_t *tmp4_optvar_seqlen;  /**< Temporary variable of length optvar_seqlen. */
real_t *tmp5_optvar_seqlen;  /**< Temporary variable of length optvar_seqlen. */
real_t *tmp6_optvar_seqlen;  /**< Temporary variable of length optvar_seqlen. */
uint32_t optvar_veclen;  /**< The length of each vector in the optimation variable sequence. */
uint32_t optvar_seqlen;  /**< The full length of optimization variable sequence. */
uint32_t sizeof_optvar_seqlen;  /**< Number of bytes in the optimization variable sequence. */
};  /**< Variables used by the fast gradient method. */

/* External function declarations */

extern void mpc_fgm_solve_problem(const struct mpc_fgm *fgm);

extern void mpc_fgm_warm_start(const struct mpc_fgm *fgm);

extern void mpc_fgm_minimize_qp_iteration(const struct mpc_fgm *fgm,
                real_t u[], real_t u_old[], real_t w[], const real_t gradoL[]);

extern void mpc_fgm_compute_grad_over_L(const struct mpc_fgm *fgm,
                real_t gradoL[], const real_t w[]);

extern void mpc_compute_gxoL(struct mpc_fgm *fgm, const real_t x[]);

#endif /* MPC_FGM_H */
