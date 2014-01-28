# Find the shortest path for a knight chess piece from 1 space to another.

class NaryTreeNode

  attr_accessor :parent, :position

  def bfs(target, print, &prc)
    queue = [self]

    until queue.empty?
      node = queue.shift
      puts node.value if print

      if block_given?
        return node if prc.call(node.value)
      end

      return node if node.value == target

      queue += node.children unless node.children.empty?
    end

    nil
  end

  def children
    @children
  end

  def children=(children)
    set_children(children)
  end

  def detach
    @parent.children.delete(self)

    @parent = nil
    @position = nil
  end

  def dfs(target, print, &prc)
    return self if @value == target

    puts @value if print

    if block_given?
      return self if prc.call(@value)
    end

    children.each do |child|
      node = child.dfs(target, print, &prc)
      return node unless node.nil?
    end

    nil
  end

  def initialize(position, parent)
    @parent = parent
    @position = position
    @children = []
  end

  def print_tree
    dfs(-1, true)
  end

  def set_children(new_children)
    @children += new_children

    new_children.each do |child|
      child.parent = self
    end
  end

  def value
    @value
  end

  def value=(new_value)
    @value = new_value
  end
  
  def build_path(bottom_node)
    path = [bottom_node.position]
    return path if bottom_node.parent == -1
    path if bottom_node.parent.nil?
    path + build_path(bottom_node.parent)
  end

end

class KnightPathFinder

  def initialize(starting_pos)
    @move_tree = NaryTreeNode.new(starting_pos, -1)
  end

  def find_path(destination)
    visited_positions = [@move_tree.position]
    queue = [@move_tree]

    until visited_positions.count == 64
      current_node = queue.shift

      unless visited_positions.include?(current_node.position)
        visited_positions << current_node.position
      end

      return build_path(current_node) if current_node.position == destination

      new_move_positions(current_node, visited_positions)
      queue += current_node.children
    end
  end

  def build_path(bottom_node)
    path = [bottom_node.position]
    return path if bottom_node.parent == -1
    path if bottom_node.parent.nil?
    path + build_path(bottom_node.parent)
  end

  def generate_permutations(x, y, start_node)
    new_positions = []
    (-2..2).each do |i|
      (-2..2).each do |j|
        next if i == 0 || j == 0 || (i == j) || (i == -j)
        new_positions << NaryTreeNode.new( [(x+i), (y+j)], start_node )
      end
    end
    new_positions
  end

  def new_move_positions(start_node, visited_coord)
    current_position = start_node.position
    x = current_position[0]
    y = current_position[1]

    new_positions = generate_permutations(x, y, start_node)

    new_positions = new_positions.reject do |node|
      pos = node.position

      (pos[0] < 0) || (pos[0] > 7) || (pos[1] < 0) ||
      (pos[1] > 7) || visited_coord.include?(pos)
    end

    start_node.children = new_positions
  end
end

kpf = KnightPathFinder.new([0, 0])
p kpf.find_path([7, 7]).reverse

