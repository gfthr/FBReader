/*
 * Copyright (C) 2009-2010 Geometer Plus <contact@geometerplus.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef __BOOK_H__
#define __BOOK_H__

#include <string>

#include <shared_ptr.h>

#include "Lists.h"

class Author;
class Tag;

class Book {

public:
	static shared_ptr<Book> createBook(
		const std::string &filePath,
		int id,
		const std::string &encoding,
		const std::string &language,
		const std::string &title
	);

	static shared_ptr<Book> loadFromFile(const std::string &filePath);

	// this method is used in Migration only
	static shared_ptr<Book> loadFromBookInfo(const std::string &filePath);

private:
	Book(const std::string filePath);

public:
	~Book();

public: // unmodifiable book methods
	const std::string &title() const;
	const std::string &filePath() const;
	const std::string &language() const;
	const std::string &encoding() const;
	const std::string &seriesTitle() const;
	int indexInSeries() const;

	const TagList &tags() const;
	const AuthorList &authors() const;

public: // modifiable book methods
	void setTitle(const std::string &title);
	void setLanguage(const std::string &language);
	void setEncoding(const std::string &encoding);
	void setSeries(const std::string &title, int index);

public:
	bool addTag(shared_ptr<Tag> tag);
	bool addTag(const std::string &fullName);
	bool removeTag(shared_ptr<Tag> tag, bool includeSubTags);
	bool renameTag(shared_ptr<Tag> from, shared_ptr<Tag> to, bool includeSubTags);
	bool cloneTag(shared_ptr<Tag> from, shared_ptr<Tag> to, bool includeSubTags);
	void removeAllTags();

	void addAuthor(shared_ptr<Author> author);
	void addAuthor(const std::string &displayName, const std::string &sortKey = std::string());
	bool replaceAuthor(shared_ptr<Author> from, shared_ptr<Author> to);
	void removeAllAuthors();

public:
	int bookId() const;
	void setBookId(int bookId);

private:
	int myBookId;

	const std::string myFilePath;
	std::string myTitle;
	std::string myLanguage;
	std::string myEncoding;
	std::string mySeriesTitle;
	int myIndexInSeries;
	TagList myTags;
	AuthorList myAuthors;

private: // disable copying
	Book(const Book &);
	const Book &operator = (const Book &);
};

inline const std::string &Book::title() const { return myTitle; }
inline const std::string &Book::filePath() const { return myFilePath; }
inline const std::string &Book::language() const { return myLanguage; }
inline const std::string &Book::encoding() const { return myEncoding; }
inline const std::string &Book::seriesTitle() const { return mySeriesTitle; }
inline int Book::indexInSeries() const { return myIndexInSeries; }

inline const TagList &Book::tags() const { return myTags; }
inline const AuthorList &Book::authors() const { return myAuthors; }

inline int Book::bookId() const { return myBookId; }
inline void Book::setBookId(int bookId) { myBookId = bookId; }

#endif /* __BOOK_H__ */
