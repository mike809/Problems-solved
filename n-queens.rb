# Solution for n-queens problem. Find the solutions for any given number
# n of queesns.

$n = 8
$board = Array.new($n) { Array.new($n) { "X" } }
$board_queens = []
$rows = []
$diagonals = []
$diagonals2 = []

def put_queens(col)
  row = 0

  if col == $n
    print_board
  else
    while row < $n
      unless any_colission?(row,col)
        add_queen(row, col)
        put_queens(col + 1)
        remove_queen(row, col)
      end
      row += 1
    end
  end
end

def add_queen(y, x)

  $board[y][x] = "Q"
  $rows << y
  $board_queens << [y,x]
  $diagonals << (x+y)
  $diagonals2 << (x-y)

end

def remove_queen(y,x)
  $board[y][x] = "X"
  $board_queens.delete([y,x])
  $rows.delete(y)
  $diagonals.delete(x+y)
  $diagonals2.delete(x-y)
end

def any_colission?(y, x)
  return true if $rows.include?(y)
  return true if $diagonals.include?(x+y)
  return true if $diagonals2.include?(x-y)
  false
end

def print_board
  $board.each do |row|
    row.each do |col|
      print "#{col} "
    end
    puts
  end
  puts
end


put_queens(0)