# Return the minimum number of coins needed to give change given  a set of coins
# denominations and a N number of change.

Infinity = +1.0/0.0

$memo = Array.new

def min_coins(n, denoms = [10,7,1])
  return [] if n == 0

  return $memo[n] if $memo[n]
  res = Infinity

  denoms.reject{ |x| x > n }.each do |denomination|

    res = [res, [denomination] + min_coins(n-denomination, denoms)].min_by do |el|
      el.class == Array ? el.count : el
    end

  end

  $memo[n] = res
end


p min_coins(39,[25,10,5,1])