# Pablo Bermejo
# https://github.com/PabloAsekas/

class LibraryManager
  
  def initialize()
    @libraries = Hash.new
  end
  
  attr_reader :libraries
  
  def addLibrary (library)
    if (@libraries[library] == nil) then
      @libraries[library] = []
    end
  end
  
  def size
    @libraries.collect { |k, v| k.size}
  end
  
  def version
    h = Hash.new
    @libraries.each { |k, v|
      h[k.name] = k.version
    }
    h
  end
  
  def addDependency(l1, l2)
    @libraries[l1].push(l2)
  end
  
  def each_dependency(l1)
    @libraries[l1].each do |e|
      yield e
    end
  end
  
  def has_dependency?(l1)
    !@libraries[l1].empty?
  end
  
  def each_deep_dependency(l1)
    all = []
    dependencies = @libraries[l1].collect { |e| e }
    while !dependencies.empty? do
      if !(all.include?(dependencies[0])) then
        all.push(dependencies[0])
        if (has_dependency?(dependencies[0])) and (l1 != dependencies[0]) then
           each_dependency(dependencies[0]) { |e| dependencies.insert(1, e) }
        end
      end
      dependencies.delete_at(0)
    end
    all.each {|e|
      yield e
    }
  end

  def libraries(c1)
    x = []
    @libraries.each { |k, v| x.push(k) if k.company == c1}
    x
  end
  
  def to_s
    "Gestor: #{@libraries}"
  end

  private :has_dependency?
  
end