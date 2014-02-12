namespace java com.cosh.c4.thrift
namespace cpp com.cosh.c4.thrift
namespace csharp cosh.c4
namespace py c4
namespace php c4
namespace perl c4
namespace rb c4Thrift

#
# Constants
#

const string VERSION = "0.0.1"

#
# TypeDefs
#
typedef i64 TRowKey
typedef i16 TColumnKey
typedef i32 TTTL
typedef binary TValue

#
# Exceptions
#

/** A specific column was requested that does not exist. */
exception NotFoundException {
}

/** Invalid request could mean required parameters are missing, or a parameter is malformed. 
    why contains an associated error message.
*/
exception InvalidRequestException {
    1: required string why
}

#
# c4 service api
#
service C4 {

	/**
	 * Inserts or updates a new row including the corresponding column with a new value
	 *
 	*/
	void InsertOrUpdate(1:required TRowKey rowId, 
			   	   2:required TColumnKey columnId, 
			   	   3:required TValue value,
			   	   4:required TTTL ttl=0)
	   	throws (1:InvalidRequestException ire),


	/**
	 * Gets a column in a row
 	*/
	TValue Get(1:required TRowKey rowId, 
		   2:required TColumnKey columnId)
		throws (1:InvalidRequestException ire),

	/**
	 * Tombstones a column in a row. Tomestones are finally deleted in the next compaction.
	 */
	void TombstoneColumn(1:required TRowKey rowId, 
                   	      2:required TColumnKey columnId)
                throws (1:InvalidRequestException ire),

	/**
	 * Tombstones a row. Tomestones are finally deleted in the next compaction.
	 */
	void TombstoneRow(1:required TRowKey rowId)
                throws (1:InvalidRequestException ire)
}

#
# c4 admin service api
#
service C4Admin {
	/**
	 * Executes a compaction
	 */
	oneway void Compact(),

	/**
	 * Cleares the column store
	 */
	oneway void TabulaRasa(),

	/**
	 * Saves the column store
	 */
	void Save(1:required string outputStream)
				throws (1:InvalidRequestException ire),

	/**
	 * Loads the columnstore
	 */
	void Load(1:required string inputStream)
				throws (1:InvalidRequestException ire),

	/**
	 * Shutdown
	 */
	oneway void Shutdown()
}
