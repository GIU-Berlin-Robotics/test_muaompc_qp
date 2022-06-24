

//use muaompc_bindgen::{mpcmydat_ctl_setup_ctl, mpc_ctl_solve_problem,
use crate::{mpcmydat_ctl_setup_ctl, mpc_ctl_solve_problem,
mpc_term, mpc_ctl};


#[derive(Debug)]
pub struct Mtx {
    pub rows: u32,
    pub cols: u32,
    pub data: Vec<f32>,
}

impl Mtx {
    fn new(M: mpc_term) -> Mtx {
        let cols = M.cols;
        let rows = M.rows;

        let data = Vec::from(
            unsafe {std::slice::from_raw_parts(M.data, (rows*cols) as usize)});
        
        Mtx {
            rows,
            cols,
            data
        }
    }

    fn new_from_pointer(P: *mut f32, rows:u32, cols:u32) -> Mtx {

        let data = Vec::from(
            unsafe {std::slice::from_raw_parts(P, (rows*cols) as usize)});
        Mtx {
            rows,
            cols,
            data
        }
    }
}


#[derive(Debug)]
pub struct QP {
    pub H: Mtx,
    pub g: Mtx,
    pub u_lb: Mtx,
    pub u_ub: Mtx,
    pub sol: Mtx,
//    pub sol: Vec<f32>,
//    pub E: Mtx,
}

impl QP {
    fn new(ctl: mpc_ctl) -> QP {
        let slv = unsafe {*ctl.solver};
        let sol = Mtx::new_from_pointer(slv.u_opt, 
        slv.optvar_seqlen, 1);
        let frm = unsafe {*ctl.former}; 
        let prb = unsafe {*frm.prb}; 
        let H = Mtx::new(unsafe{*prb.H});
        let g = Mtx::new(unsafe{*prb.g});
        let u_lb = Mtx::new(unsafe{*prb.u_lb});
        let u_ub = Mtx::new(unsafe{*prb.u_ub});
//        let E = Mtx::new(unsafe{*prb.E});
        QP {
            H,
            g,
            u_lb,
            u_ub,
            sol
        }
    }
}

pub fn load_qp_problem() -> QP {
    let mut ctl = unsafe {
        let ctl = mpcmydat_ctl_setup_ctl();
        (*(*(*ctl).solver).conf).in_iter = 10;
        *ctl
    };
    let par = unsafe {
        *ctl.parameters
    };
    let x_bar = par.x_bar;
    unsafe {*x_bar = 10.};
    unsafe {*(x_bar.add(1)) =- 10.};
    
//    let slv = unsafe {*ctl.solver}; 
//    let mut conf = unsafe {*slv.conf}; 
//    hprintln!("conf: {} ", conf.in_iter).unwrap();
    unsafe {mpc_ctl_solve_problem(&mut ctl)};


    QP::new(ctl)
}