# Pablo Bermejo
# https://github.com/PabloAsekas/

class Library
  def initialize(name, version, size, company)
    @name, @version, @size, @company = name, version, size, company
  end
  
  attr_reader :name, :version, :size, :company
  
  def to_s
    "#{@name} - #{@version} - #{@size} - #{@company}"
  end
  
end