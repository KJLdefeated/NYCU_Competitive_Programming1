fun main() {
    val (n, k) = readLine()!!.split(" ").map{ it.toBigInteger() }
    if (k > "400".toBigInteger() || n <= "2".toBigInteger().pow(k.toInt())) {
        println("Your wish is granted!")
    } else {
        println("You will become a flying monkey!")
    }
}