use test_muaompc_qp as muao;
fn main() {

    let qp = muao::qp::load_qp_problem();
    
    println!("QP: {:?}", qp);

}
