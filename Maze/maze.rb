# Maze solver. Solve any maze with a bfs algorithm.

require_relative 'NnaryTree'

class MazeSolver < NnaryTreeNode
  DIFF = [[1,0], [-1,0], [0,1], [0, -1]]
   
  attr_accessor :start, :target, :maze
  
  def initialize(maze_path)
    @start = []
    @target = []
    @maze = parse_maze(maze_path)
    @path_finder = NnaryTreeNode.new(@start, -1)
    @path_finder = find_path(@target)
  end
  
  def parse_maze(maze_path)
    graph = []
    line_count = 0
    File.foreach(maze_path) do |line|
      row = []    
      line.chomp.split('').each_with_index do |spot, idx|

        if spot == "*"
          row << false
        elsif spot == " "
          row << true
        else
          if spot == "S"
            @start = [line_count, idx] 
          else
            @target = [line_count, idx]
          end
          row << spot
        end
      end
      line_count += 1
      graph << row
    end
    graph
  end
  
  def find_path(destination)
    visited_positions = [@path_finder.position]
    queue = [@path_finder]

    until queue.empty?
      current_node = queue.shift
      visited_positions << current_node.position

      return build_path(current_node) if current_node.position == destination
      
      new_nodes = generate_children(current_node)
      
      new_nodes.reject! do |child| 
        visited_positions.include?(child.position)
      end  
          
      new_nodes ||= current_node.children
  
      visited_positions += new_nodes.map{ |child| child.position}
      queue += new_nodes
    end
  end
  
  def generate_permutations(x, y, start_node)
    new_positions = []
    DIFF.each do |coord|
      next if @maze[x+coord[0]][y+coord[1]] == false
      new_positions << NnaryTreeNode.new([(x+coord[0]), (y+coord[1])], start_node)
    end
    new_positions
  end

  def generate_children(start_node)
    current_position = start_node.position
    x = current_position[0]
    y = current_position[1]

    new_positions = generate_permutations(x, y, start_node)
    start_node.children = new_positions
  end
  
  def build_path(bottom_node)
    path = [bottom_node.position]
    pos = path[0]
  
    @maze[pos[0]][pos[1]] = "$"
    return path if bottom_node.parent == -1
    path if bottom_node.parent.nil?
    path + build_path(bottom_node.parent)
  end
  
  def show
    @maze.each do |row|
      row.each do |spot|
       if spot == false
         print "*"
       elsif spot == true
         print " "
       else
         print spot
       end  
      end
      puts
    end
  end
  
end
  
maze_solver = MazeSolver.new("example_maze3.txt")

maze_solver.show





