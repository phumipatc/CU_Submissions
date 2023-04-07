package lecture01_commonfeatures

object ComplexIf {
  def main(args: Array[String]): Unit = {
    var a = 15
    var b = 3;
    var c = 20
    if(a<16){
      if(b>3 && c <=20){
        println("case 1.1")
      }else if (b>3 && c ==20){
        println("case 1.2")
      }else if (b>3 && c>20){
        println("case 1.3")
      }else {
        println("case 1.4")
      }
    } else if (a == 16 || b!=4){
      println("case 2.1")
    } else {
      println("case 3.1")
    }
  }
}
