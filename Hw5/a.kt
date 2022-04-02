fun main() {
    val (a, b) = readLine()!!.split(" ").filter{ it.length > 0 }
    val n = a.toBigInteger()
    if (n.lowestSetBit != 0) {
        println(n.shiftRight(1).modPow(b.toBigInteger(), n))
    } else {
        println("0")
    }
}