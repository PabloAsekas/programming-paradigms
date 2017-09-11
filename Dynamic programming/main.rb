# Pablo Bermejo
# https://github.com/PabloAsekas/

require "Library"
require "LibraryManager"

gestor = LibraryManager.new()

a = Library.new("a", "1.1", 45, "Google")
gestor.addLibrary(a)
b = Library.new("b", "2.2", 32, "Facebook")
gestor.addLibrary(b)
c = Library.new("c", "1.1", 45, "Twitter")
gestor.addLibrary(c)
d = Library.new("d", "1.1", 45, "Google")
gestor.addLibrary(d)
f = Library.new("f", "2.2", 45, "Uber")
gestor.addLibrary(f)
g = Library.new("g", "2.2", 45, "Microsoft")
gestor.addLibrary(g)

puts "Manager ------"
p gestor

puts "Size ------"
p gestor.size()

puts "Versions ------"
puts gestor.version()

gestor.addDependency(a, b)
gestor.addDependency(a, c)
gestor.addDependency(a, d)
gestor.addDependency(c, a)
gestor.addDependency(c, f)

puts "Manager with dependencies added ------"
p gestor

puts "Simple dependencies of a ------"
gestor.each_dependency(a) {|e| puts e}
  
puts "Deep dependencies of a ------"
gestor.each_deep_dependency(a) { |e| puts e}

puts "Google's libraries ------"
p gestor.libraries("Google")